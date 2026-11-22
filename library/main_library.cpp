#include "Library.h"

int main() {
    DatabaseBookRepository repository;
    EmailNotificationService emailService;
    ConsoleBookPresenter presenter;

    Library library(repository, emailService, presenter);

    library.addBook(Book("The Catcher in the Rye", "J.D. Salinger"));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee"));
    library.displayBooks();

    return 0;
}