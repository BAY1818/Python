
class Car:
    def __init__(self,brand,model,rental_price):
        self.brand = brand
        self.model = model
        self.rental_price = rental_price
        self.is_rented = False
    def __str__(self):
        return f"{self.brand} {self.model} rental price:${self.rental_price}/day"

class RentalService:
    def __init__(self):
        self.cars = []
    def add_car(self,car):
        self.cars.append(car)
        print(f"Car {car.brand} is added")
    def available_cars(self):
        for car in self.cars:
            if not car.is_rented:
                print(car)
    def rent_car(self,brand,model):
        for car in self.cars:
            if car.brand == brand and car.model == model and not car.is_rented:
                car.is_rented = True
                print(f"Car {car.brand} {car.model} Rental price:${car.rental_price}/day was rented successfully")
                return
            print("This car is not available in our Service!!")
    def return_car(self,brand,model):
        for car in self.cars:
            if car.brand == brand and car.model == model and car.is_rented:
                car.is_rented = False
                print(f"Car {car.model} {car.brand} was returned without damage!!")
                return
        print("This brand of car is not our company's!!")

service = RentalService()

car1 = Car("Lada","Kalina", 80)
car2 = Car("BMW","M5",640)
car3 = Car("Toyota","Camry",240)

service.add_car(car1)
service.add_car(car2)
service.add_car(car3)

service.available_cars()

service.rent_car("Toyota","Camry")

service.return_car("Toyota", "Camry")

