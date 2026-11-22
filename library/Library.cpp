#include "Library.h"
#include <iostream>
#include <utility>

Book::Book(std::string title, std::string author)
    : title(std::move(title)), author(std::move(author)) {}

const std::string& Book::getTitle() const {
    return title;
}

const std::string& Book::getAuthor() const {
    return author;
}

void DatabaseBookRepository::save(const Book& book) {
    storage.push_back(book);
    std::cout << "Saving book '" << book.getTitle() << "' to database..." << std::endl;
}

std::vector<Book> DatabaseBookRepository::findAll() const {
    return storage;
}

void EmailNotificationService::notifyNewBook(const Book& book) {
    std::cout << "Sending email notification about the new book: "
              << book.getTitle() << std::endl;
}

void ConsoleBookPresenter::displayAll(const std::vector<Book>& books) const {
    for (const auto& book : books) {
        std::cout << "Title: " << book.getTitle()
                  << ", Author: " << book.getAuthor() << std::endl;
    }
}

Library::Library(IBookRepository& repository,
                 INotificationService& notificationService,
                 IBookPresenter& presenter)
    : repository(repository),
      notificationService(notificationService),
      presenter(presenter) {}

void Library::addBook(const Book& book) {
    repository.save(book);
    notificationService.notifyNewBook(book);
}

void Library::displayBooks() const {
    presenter.displayAll(repository.findAll());
}