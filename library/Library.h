#pragma once
#include <string>
#include <vector>

class Book {
public:
    Book(std::string title, std::string author);
    const std::string& getTitle() const;
    const std::string& getAuthor() const;

private:
    std::string title;
    std::string author;
};

class IBookRepository {
public:
    virtual void save(const Book& book) = 0;
    virtual std::vector<Book> findAll() const = 0;
    virtual ~IBookRepository() = default;
};

class INotificationService {
public:
    virtual void notifyNewBook(const Book& book) = 0;
    virtual ~INotificationService() = default;
};

class IBookPresenter {
public:
    virtual void displayAll(const std::vector<Book>& books) const = 0;
    virtual ~IBookPresenter() = default;
};

class DatabaseBookRepository : public IBookRepository {
public:
    void save(const Book& book) override;
    std::vector<Book> findAll() const override;

private:
    std::vector<Book> storage;
};

class EmailNotificationService : public INotificationService {
public:
    void notifyNewBook(const Book& book) override;
};

class ConsoleBookPresenter : public IBookPresenter {
public:
    void displayAll(const std::vector<Book>& books) const override;
};

class Library {
public:
    Library(IBookRepository& repository,
            INotificationService& notificationService,
            IBookPresenter& presenter);

    void addBook(const Book& book);
    void displayBooks() const;

private:
    IBookRepository& repository;
    INotificationService& notificationService;
    IBookPresenter& presenter;
};