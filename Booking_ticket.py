
class Passenger:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def __str__(self):
        return f"Name:{self.name} Age:{self.age}"


class Train:
    def __init__(self, total_seats):
        self.total_seats = total_seats
        self.available_seats = total_seats
        self.passenger_list = []

    def book_seat(self, passenger):
        if isinstance(passenger, Passenger):
            if self.available_seats > 0:
                self.passenger_list.append(passenger)
                self.available_seats -= 1
                print(f"Seat book successfully by {passenger.name}.")
            else:
                print(f"No seats available!!!")

    def show_booking(self):
        if self.passenger_list:
            print("Booked passengers")
            for passenger in self.passenger_list:
                print(passenger.name)
        else:
            print("No seats booked yet!!!")


p1 = Passenger("NF", 35)
p2 = Passenger("Eminem", 40)
p3 = Passenger("Syke", 37)

t1 = Train(3)
t1.book_seat(p1)
t1.book_seat(p2)
t1.book_seat(p3)

t1.show_booking()
