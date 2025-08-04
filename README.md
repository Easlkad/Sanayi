# Oto Teknik Sanayi Management System

A modern Qt/QML-based automotive service management application designed for tracking vehicle transactions, service records, and customer information.

## 🚗 Overview

Oto Teknik Sanayi is a comprehensive desktop application built for automotive service businesses to manage:
- Vehicle service transactions
- Customer records
- Service history tracking
- Financial calculations (debt, receivables, external costs)
- Spare parts management
- Print receipts and reports

## ✨ Features

- **Modern UI**: Clean and intuitive interface built with Qt Quick/QML
- **Transaction Management**: Add, edit, and track service transactions
- **Search & Filter**: Advanced search functionality with date range filtering
- **Database Integration**: SQLite database for reliable data storage
- **Print Support**: Generate and print service receipts
- **Real-time Updates**: Live data updates across the application
- **Customer Management**: Track customer information and service history
- **Financial Tracking**: Monitor debts, receivables, and external costs

## 🛠️ Technology Stack

- **Framework**: Qt 6.9.1
- **Language**: C++17
- **UI**: QML (Qt Quick)
- **Database**: SQLite (Qt SQL)
- **Build System**: CMake
- **Platform**: Cross-platform (Windows, Linux, macOS)

## 📋 Prerequisites

- Qt 6.5 or higher
- CMake 3.16 or higher
- C++17 compatible compiler
- MinGW-w64 (for Windows) or appropriate compiler for your platform

### Required Qt Modules
- Qt6::Core
- Qt6::Quick
- Qt6::Sql
- Qt6::QuickControls2
- Qt6::Gui
- Qt6::PrintSupport

## 🚀 Installation & Setup

### 1. Clone the Repository
```bash
git clone https://github.com/Easlkad/Sanayi.git
cd Sanayi
```

### 2. Build the Project

#### Using Qt Creator
1. Open `CMakeLists.txt` in Qt Creator
2. Configure the project with your Qt kit
3. Build and run

#### Using Command Line
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### 3. Run the Application
```bash
./appSanayi
```

## 📱 Usage

### Main Interface
- **Header**: Contains the application title and search functionality
- **Transaction Table**: Displays all service records with sorting and filtering
- **Add/Edit Forms**: Intuitive forms for managing transaction data

### Key Operations
1. **Adding Transactions**: Fill in vehicle details, service information, and costs
2. **Searching**: Use the search bar to find specific transactions
3. **Date Filtering**: Filter transactions by date range
4. **Printing**: Generate receipts for completed services
5. **Data Management**: Edit or update existing transaction records

## 🗂️ Project Structure

```
Sanayi/
├── CMakeLists.txt          # Build configuration
├── main.cpp                # Application entry point
├── DatabaseManager.h/cpp   # Database operations
├── transactionmodel.h/cpp  # Data model for transactions
├── printmanager.h/cpp      # Print functionality
├── Main.qml               # Main application interface
├── SearchBar.qml          # Search component
├── TransactionTable.qml   # Transaction display table
├── DatePicker.qml         # Date selection component
├── ModernButton.qml       # Custom button component
├── resources.qrc          # Resource file
└── build/                 # Build output directory
```

## 🔧 Configuration

The application automatically creates and initializes the SQLite database on first run. Database tables include:
- Transaction records
- Customer information
- Vehicle details
- Service history

## 🖥️ Screenshots

*Add screenshots of your application here*

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 👥 Authors

- **Easlkad** - *Initial work* - [@Easlkad](https://github.com/Easlkad)

## 🐛 Bug Reports & Feature Requests

Please use the [GitHub Issues](https://github.com/Easlkad/Sanayi/issues) page to report bugs or request new features.


## 🔄 Version History

- **v0.1** - Initial release
  - Basic transaction management
  - SQLite database integration
  - Modern QML interface
  - Print functionality

## 🙏 Acknowledgments

- Qt Framework for providing excellent cross-platform development tools
- The automotive service industry for inspiring this solution
- Contributors and users for their valuable feedback

---

*Built with ❤️ for the automotive service industry*
