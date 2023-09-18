#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Book {
public:
    string bookName;
    string authorName;
    int numPages;
    double price;
    string publishDate;
    Book* next;
};
Book* head = nullptr;
void Insert_Record(string bookName, string authorName, int numPages, double price, string publishDate) {
    Book* newBook = new Book();
    newBook->bookName = bookName;
    newBook->authorName = authorName;
    newBook->numPages = numPages;
    newBook->price = price;
    newBook->publishDate = publishDate;
    newBook->next = nullptr;
    if (head == nullptr || head->price >= newBook->price) {
        newBook->next = head;
        head = newBook;
        cout << "Book Record Inserted Successfully\n";
        return;
    }
    Book* current = head;
    while (current->next != nullptr && current->next->price < newBook->price) {
        current = current->next;
    }
    newBook->next = current->next;
    current->next = newBook;
    cout << "Book Record Inserted Successfully\n";
}
void Delete_Record(string bookName) {
    if (head == nullptr) {
        cout << "No book records available\n";
        return;
    }
    if (head->bookName == bookName) {
        Book* temp = head;
        head = head->next;
        delete temp;
        cout << "Book Record Deleted Successfully\n";
        return;
    }
    Book* current = head;
    while (current->next != nullptr && current->next->bookName != bookName) {
        current = current->next;
    }
    if (current->next == nullptr) {
        cout << "Book Record not found\n";
    } else {
        Book* temp = current->next;
        current->next = current->next->next;
        delete temp;
        cout << "Book Record Deleted Successfully\n";
    }
}
void Show_Record() {
    if (head == nullptr) {
        cout << "No book records available\n";
    } else {
        Book* current = head;
        int bookNumber = 1;
        while (current != nullptr) {
            cout << "\nDetails of book " << bookNumber << ":\n";
            cout << "Book Name: " << current->bookName << "\n"
                 << "Author Name: " << current->authorName << "\n"
                 << "Pages: " << current->numPages << "\n"
                 << "Price: " << current->price << "\n"
                 << "Publish Date: " << current->publishDate << endl; // Display publish date
            current = current->next;
            bookNumber++;
        }
    }
}
void QuickSort(Book* left, Book* right) {
    if (left == nullptr || right == nullptr || left == right || left->next == right)
        return;
    Book* pivot = left;
    Book* current = left->next;
    double pivotPrice = pivot->price;
    while (current != right->next) {
        if (current->price < pivotPrice) {
            pivot = pivot->next;
            swap(pivot->price, current->price);
            swap(pivot->bookName, current->bookName);
            swap(pivot->authorName, current->authorName);
            swap(pivot->numPages, current->numPages);
            swap(pivot->publishDate, current->publishDate);
        }
        current = current->next;
    }
    swap(pivot->price, left->price);
    swap(pivot->bookName, left->bookName);
    swap(pivot->authorName, left->authorName);
    swap(pivot->numPages, left->numPages);
    swap(pivot->publishDate, left->publishDate);
    QuickSort(left, pivot);
    QuickSort(pivot->next, right);
}
void Sort_By_Price() {
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    Book* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    QuickSort(head, last);
    cout << "Books sorted by price:\n";
    Show_Record();
}
void QuickSortByName(Book* left, Book* right) {
    if (left == nullptr || right == nullptr || left == right || left->next == right)
        return;
    Book* pivot = left;
    Book* current = left->next;
    string pivotName = pivot->bookName;
    while (current != right->next) {
        if (current->bookName < pivotName) {
            pivot = pivot->next;
            swap(pivot->bookName, current->bookName);
            swap(pivot->authorName, current->authorName);
            swap(pivot->numPages, current->numPages);
            swap(pivot->price, current->price);
            swap(pivot->publishDate, current->publishDate);
        }
        current = current->next;
    }
    swap(pivot->bookName, left->bookName);
    swap(pivot->authorName, left->authorName);
    swap(pivot->numPages, left->numPages);
    swap(pivot->price, left->price);
    swap(pivot->publishDate, left->publishDate);
    QuickSortByName(left, pivot);
    QuickSortByName(pivot->next, right);
}
void Sort_By_Name() {
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    Book* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    QuickSortByName(head, last);
    cout << "Books sorted by name in alphabetical order:\n";
    Show_Record();
}
void QuickSortByAuthorName(Book* left, Book* right) {
    if (left == nullptr || right == nullptr || left == right || left->next == right)
        return;
    Book* pivot = left;
    Book* current = left->next;
    string pivotAuthor = pivot->authorName;
    while (current != right->next) {
        if (current->authorName < pivotAuthor) {
            pivot = pivot->next;
            swap(pivot->bookName, current->bookName);
            swap(pivot->authorName, current->authorName);
            swap(pivot->numPages, current->numPages);
            swap(pivot->price, current->price);
            swap(pivot->publishDate, current->publishDate); // Swap publish date
        }
        current = current->next;
    }
    swap(pivot->bookName, left->bookName);
    swap(pivot->authorName, left->authorName);
    swap(pivot->numPages, left->numPages);
    swap(pivot->price, left->price);
    swap(pivot->publishDate, left->publishDate);
    QuickSortByAuthorName(left, pivot);
    QuickSortByAuthorName(pivot->next, right);
}
void Sort_By_Author_Name() {
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    Book* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    QuickSortByAuthorName(head, last);
    cout << "Books sorted by author's name in alphabetical order:\n";
    Show_Record();
}
void QuickSortByPublishDate(Book* left, Book* right) {
    if (left == nullptr || right == nullptr || left == right || left->next == right)
        return;
    Book* pivot = left;
    Book* current = left->next;
    string pivotDate = pivot->publishDate;
    while (current != right->next) {
        if (current->publishDate < pivotDate) {
            pivot = pivot->next;
            swap(pivot->bookName, current->bookName);
            swap(pivot->authorName, current->authorName);
            swap(pivot->numPages, current->numPages);
            swap(pivot->price, current->price);
            swap(pivot->publishDate, current->publishDate); // Swap publish date
        }
        current = current->next;
    }
    swap(pivot->bookName, left->bookName);
    swap(pivot->authorName, left->authorName);
    swap(pivot->numPages, left->numPages);
    swap(pivot->price, left->price);
    swap(pivot->publishDate, left->publishDate);
    QuickSortByPublishDate(left, pivot);
    QuickSortByPublishDate(pivot->next, right);
}
void Sort_By_Publish_Date() {
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    Book* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    QuickSortByPublishDate(head, last);
    cout << "Books sorted by publish date in chronological order:\n";
    Show_Record();
}
void List_Books_By_Author(string authorName) {
    if (head == nullptr) {
        cout << "No book records available\n";
        return;
    }
    Book* current = head;
    int bookNumber = 1;
    bool found = false;
    while (current != nullptr) {
        if (current->authorName == authorName) {
            found = true;
            cout << "\nDetails of book " << bookNumber << ":\n";
            cout << "Book Name: " << current->bookName << "\n"
                 << "Author Name: " << current->authorName << "\n"
                 << "Pages: " << current->numPages << "\n"
                 << "Price: " << current->price << "\n"
                 << "Publish Date: " << current->publishDate << endl; // Display publish date
            bookNumber++;
        }
        current = current->next;
    }
    if (!found) {
        cout << "No books by the author '" << authorName << "' found.\n";
    }
}
int Count_Books() {
    int count = 0;
    Book* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}
int main() {
    string bookName, authorName, publishDate; // Added publishDate
    int numPages;
    double price;
    Book* book1 = new Book();
    book1->bookName = "The Catcher in the Rye";
    book1->authorName = "J.D. Salinger";
    book1->numPages = 277;
    book1->price = 1500;
    book1->publishDate = "1951";
    book1->next = nullptr;
    Book* book2 = new Book();
    book2->bookName = "To Kill a Mockingbird";
    book2->authorName = "Harper Lee";
    book2->numPages = 336;
    book2->price = 1200;
    book2->publishDate = "1960";
    book2->next = nullptr;
    Book* book3 = new Book();
    book3->bookName = "The Great Gatsby";
    book3->authorName = "F. Scott Fitzgerald";
    book3->numPages = 180;
    book3->price = 800;
    book3->publishDate = "1925";
    book3->next = nullptr;
    Book* book4 = new Book();
    book4->bookName = "1984";
    book4->authorName = "George Orwell";
    book4->numPages = 328;
    book4->price = 1500;
    book4->publishDate = "1949";
    book4->next = nullptr;
    Book* book5 = new Book();
    book5->bookName = "Pride and Prejudice";
    book5->authorName = "Jane Austen";
    book5->numPages = 432;
    book5->price = 900;
    book5->publishDate = "1813";
    book5->next = nullptr;
    Book* book6 = new Book();
    book6->bookName = "The Hobbit";
    book6->authorName = "J.R.R. Tolkien";
    book6->numPages = 310;
    book6->price = 1100;
    book6->publishDate = "1937";
    book6->next = nullptr;
    Book* book7 = new Book();
    book7->bookName = "The Alchemist";
    book7->authorName = "Paulo Coelho";
    book7->numPages = 208;
    book7->price = 800;
    book7->publishDate = "1988";
    book7->next = nullptr;
    Book* book8 = new Book();
    book8->bookName = "The Hunger Games";
    book8->authorName = "Suzanne Collins";
    book8->numPages = 374;
    book8->price = 1400;
    book8->publishDate = "2008";
    book8->next = nullptr;
    Book* book9 = new Book();
    book9->bookName = "The Da Vinci Code";
    book9->authorName = "Dan Brown";
    book9->numPages = 454;
    book9->price = 1250;
    book9->publishDate = "2003";
    book9->next = nullptr;
    Book* book10 = new Book();
    book10->bookName = "The Lord of the Rings";
    book10->authorName = "J.R.R. Tolkien";
    book10->numPages = 1178;
    book10->price = 2000;
    book10->publishDate = "1954";
    book10->next = nullptr;
    Book* book11 = new Book();
    book11->bookName = "The Shining";
    book11->authorName = "Stephen King";
    book11->numPages = 447;
    book11->price = 1300;
    book11->publishDate = "1977";
    book11->next = nullptr;
    Book* book12 = new Book();
    book12->bookName = "Brave New World";
    book12->authorName = "Aldous Huxley";
    book12->numPages = 325;
    book12->price = 1100;
    book12->publishDate = "1932";
    book12->next = nullptr;
    Book* book13 = new Book();
    book13->bookName = "The Road";
    book13->authorName = "Cormac McCarthy";
    book13->numPages = 287;
    book13->price = 1200;
    book13->publishDate = "2006";
    book13->next = nullptr;
    Book* book14 = new Book();
    book14->bookName = "Moby-Dick";
    book14->authorName = "Herman Melville";
    book14->numPages = 635;
    book14->price = 1400;
    book14->publishDate = "1851";
    book14->next = nullptr;
    Book* book15 = new Book();
    book15->bookName = "The Road Less Traveled";
    book15->authorName = "M. Scott Peck";
    book15->numPages = 316;
    book15->price = 1000;
    book15->publishDate = "1978";
    book15->next = nullptr;
    book1->next = book2;
    book2->next = book3;
    book3->next = book4;
    book4->next = book5;
    book5->next = book6;
    book6->next = book7;
    book7->next = book8;
    book8->next = book9;
    book9->next = book10;
    book10->next = book11;
    book11->next = book12;
    book12->next = book13;
    book13->next = book14;
    book14->next = book15;
    head = book1;
    cout << "<---------------------- WELCOME TO E-LIBRARY ---------------------->" << endl;
    while (true) {
        // Display menu options and get user input
        cout << "\nEnter 1 to create a new Book Record\n"
             << "Enter 2 to delete a Book record\n"
             << "Enter 3 to list count of all Books in the library\n"
             << "Enter 4 to list Books by author's name\n"
             << "Enter 5 to view all Book records\n"
             << "Enter 6 to sort Books by price\n"
             << "Enter 7 to sort Books by name\n"
             << "Enter 8 to sort Books by author's name\n"
             << "Enter 9 to sort Books by publish date\n"
             << "Enter 10 to exit\n"
             << endl;
        cout << "Enter your choice : ";
        int Choice;
        cin >> Choice;
        cout << "\n";
        if (Choice == 1) {
            // Collect book information from the user, including publish date
            cout << "\nEnter the Name of the Book: ";
            cin.ignore();
            getline(cin, bookName);
            cout << "\nEnter the Author of the Book: ";
            getline(cin, authorName);
            cout << "\nEnter the Number of Pages: ";
            cin >> numPages;
            cout << "\nEnter the Price of the Book: ";
            cin >> price;
            cout << "\nEnter the Publish Date of the Book: ";
            cin.ignore();
            getline(cin, publishDate);
            // Insert the book record with publish date
            Insert_Record(bookName, authorName, numPages, price, publishDate);
        } else if (Choice == 2) {
            cout << "Enter the Name of the Book to delete\n";
            cin.ignore();
            getline(cin, bookName);
            Delete_Record(bookName);
        } else if (Choice == 3) {
            int bookCount = Count_Books();
            cout << "\nTotal number of books in the library: " << bookCount << endl;
        } else if (Choice == 4) {
            cout << "\nEnter the Author Name to list books by author:\n";
            cin.ignore();
            getline(cin, authorName);
            List_Books_By_Author(authorName);
        } else if (Choice == 5) {
            Show_Record();
        } else if (Choice == 6) {
            Sort_By_Price();
        } else if (Choice == 7) {
            Sort_By_Name();
        } else if (Choice == 8) {
            Sort_By_Author_Name();
        } else if (Choice == 9) {
            Sort_By_Publish_Date();
        } else if (Choice == 10) {
            cout << "Exit Successful\n";
            break;
        } else {
            cout << "Error\n";
        }
        cout << "\n<------------------------------------------------------------------>" << endl;
    }
    Book* current = head;
    while (current != nullptr) {
        Book* next = current->next;
        delete current;
        current = next;
    }
    return 0;
}