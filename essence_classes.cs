public class Author //1----
{
    public int Id { get; set; }
    public string FirstName { get; set; }
    public string LastName { get; set; }
    public DateTime? BirthDate { get; set; }
    public string? Country { get; set; }

    public ICollection<Book> Books { get; set; } = new List<Book>();
}
public class Genre //2----
{
    public int Id { get; set; }
    public string Name { get; set; }
    public string? Description { get; set; }
    public ICollection<Book> Books { get; set; } = new List<Book>();
}
public class Book //3----
{
    public int Id { get; set; }
    public string Title { get; set; }
    public int Year { get; set; }
    public int AuthorId { get; set; }
    public int GenreId { get; set; }

    public Author Author { get; set; }
    public Genre Genre { get; set; }
    public ICollection<Borrow> Borrows { get; set; } = new List<Borrow>();
}
public class Reader //4----
{
    public int Id { get; set; }
    public string FirstName { get; set; }
    public string LastName { get; set; }
    public string Email { get; set; }
    public string Phone { get; set; }

    public ICollection<Borrow> Borrows { get; set; } = new List<Borrow>();
}
public class Borrow //5----
{
    public int Id { get; set; }
    public int BookId { get; set; }
    public int ReaderId { get; set; }
    public DateTime BorrowDate { get; set; }
    public DateTime? ReturnDate { get; set; }

    public Book Book { get; set; }
    public Reader Reader { get; set; }
}
