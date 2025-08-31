class Book:
    def __init__(self, title, author, isbn):
        self.title = title  # Store the book title
        self.author = author  # Store the author's name
        self.isbn = isbn  # Store the book's ISBN (unique identifier)

class Library:
    def __init__(self):
        self.books = []  # Create an empty list to store books

    def add_book(self, book):
        self.books.append(book)  # Add the book object to the list
        print(f"Book '{book.title}' added to the library!")

    def remove_book(self, isbn):
        for book in self.books:
            if book.isbn == isbn:
                self.books.remove(book)
                print(f"Book '{book.title}' removed from the library!")
                return
        print("Book not found!")  

    # Method to search for books by title or author
    def search_book(self, query):
        found_books = []  # List to store search results
        for book in self.books:  # Loop through books
            if query.lower() in book.title.lower() or query.lower() in book.author.lower():
                found_books.append(book)  # Add matching books to the list

        if found_books:  # If we found books, display them
            print("Search results:")
            for book in found_books:
                print(f"Title: {book.title}, Author: {book.author}, ISBN: {book.isbn}")
        else:
            print("No matching books found.")  # If no books match, print this

# Create a Library object
library = Library()

# Create Book objects
book1 = Book("Harry Potter", "J.K. Rowling", "123456789")
book2 = Book("The Hobbit", "J.R.R. Tolkien", "987654321")

# Add books to the library
library.add_book(book1)
library.add_book(book2)

# Search for a book
library.search_book("Harry")

# Remove a book
library.remove_book("123456789")

# Show remaining books
print("Current books in the library:")
for book in library.books:
    print(f"Title: {book.title}, Author: {book.author}, ISBN: {book.isbn}")
