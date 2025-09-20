# ✈️ SSE Flight Management System

A **C++ + Qt + MySQL** based Flight Management System.  
It allows passengers to search flights, purchase tickets, refund or reschedule, choose seats, and manage personal info.  
Administrators can add, delete, modify, and query flights, ensuring efficient flight operations management.

---

## 📖 Features

### Passenger Functions
- Register, login, and logout  
- Search flights (by flight number, date, origin, destination, etc.)  
- Book, pay, refund, and reschedule tickets  
- Seat selection and check-in, luggage check reminders  
- View and manage personal info and orders  
- Receive flight notifications (inbox)  

### Administrator Functions
- Login as admin  
- Add, delete, modify, and query flight information  
- Manage passenger orders  
- Publish flight delay/cancellation notifications  

---

## 🛠 Tech Stack

- **Language**: C++  
- **Database**: MySQL  
- **GUI Framework**: Qt (cross-platform)  
- **Environment**: Windows 10 + Qt 6.0 + MySQL  

---

## 📂 System Modules

- Passenger Information Management  
- Flight Information Management  
- Order Management  
- System Information Management  
- Seat Selection & Check-in  
- Notification Management (Inbox)  

---

## 🚀 Getting Started

### 1. Clone the repo
```bash
git clone https://github.com/your-username/Airline-Ticketing-System.git
cd sse-flight-management
```

### 2. Database setup
1. Create a MySQL database named `flight_sys`  
2. Import the provided `schema.sql` (includes tables for users, flights, orders, seats, etc.)  

### 3. Build & Run
Using Qt Creator to build, or via terminal:
```bash
qmake && make
./flight_sys
```

---

## 📊 Project Plan & Timeline

- **Requirement Development**: 2024.11.17  
- **Module Design**: 2024.12.08  
- **Implementation**: 2024.11.17 – 2024.12.24  
- **Testing**: 2024.12.24 – 2024.12.26  
- **Documentation & Submission**: 2024.12.26 – 2024.12.27  

---

## 🧪 Testing

Black-box testing covered:  
- Login / Register / Forgot Password  
- Flight add, delete, modify, query  
- Ticket booking, refund, reschedule  
- Seat selection & check-in  
- Order management  
- Flight notifications  

---

## 👥 Team Members

- **Liu Minghui** — Flight query, admin module, overall design  
- **Li Fengxing** — Seat selection, ticket purchase, DB integration  
- **Shi Kexin** — User/admin login & registration, requirements analysis  
- **Liu Jia** — Order management, boarding pass, inbox, documentation  

---

## 📜 License

This project is for **educational and experimental purposes only**.  
