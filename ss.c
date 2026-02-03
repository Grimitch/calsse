public interface IRepository<T> where T : class
{
    Task<T> GetByIdAsync(int id);
    Task<IEnumerable<T>> GetAllAsync();
    Task AddAsync(T entity);
    Task UpdateAsync(T entity);
    Task DeleteAsync(int id);
}

public class Repository<T> : IRepository<T> where T : class
{
    private readonly LibraryDbContext _context;
    private readonly DbSet<T> _dbSet;

    public Repository(LibraryDbContext context)
    {
        _context = context;
        _dbSet = context.Set<T>();
    }

    public async Task<T> GetByIdAsync(int id) => await _dbSet.FindAsync(id);
    public async Task<IEnumerable<T>> GetAllAsync() => await _dbSet.ToListAsync();
    public async Task AddAsync(T entity) => await _dbSet.AddAsync(entity);
    public async Task UpdateAsync(T entity) => _dbSet.Update(entity);
    public async Task DeleteAsync(int id)
    {
        var entity = await GetByIdAsync(id);
        if (entity != null) _dbSet.Remove(entity);
    }

    public async Task SaveAsync() => await _context.SaveChangesAsync();
}

public interface IBookRepository : IRepository<Book>
{
    Task<IEnumerable<Book>> GetBooksByAuthorAsync(int authorId);
    Task<IEnumerable<Book>> GetBooksByGenreAsync(int genreId);
}

public class BookRepository : Repository<Book>, IBookRepository
{
    public BookRepository(LibraryDbContext context) : base(context) { }

    public async Task<IEnumerable<Book>> GetBooksByAuthorAsync(int authorId)
    {
        return await _context.Books.Where(b => b.AuthorId == authorId).ToListAsync();
    }

    public async Task<IEnumerable<Book>> GetBooksByGenreAsync(int genreId)
    {
        return await _context.Books.Where(b => b.GenreId == genreId).ToListAsync();
    }
}
