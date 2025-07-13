
class Product:
    def __init__(self,name,price):
        self.name = name
        self.price = price
class Order:
    def __init__(self):
        self.products = []
    def add_product(self,product):
        self.products.append(product)
        print(f"Product {product.name} was ordered!")
    def calculate_total(self):
        total = sum(product.price for product in self.products)
        return total
class Customer:
    def __init__(self,name):
        self.name = name
        self.orders = []
    def order_place(self,order):
        self.orders.append(order)
        print(f"Order placed by {self.name}")
    def get_order_summary(self):
        print(f"\n Order summary for {self.name}")
        for i,order in enumerate(self.orders, start=1):
            print(f"Order{i}: $ {order.calculate_total():.2f}")
            print(f"Total orders {len(self.orders)}\n")


product1 = Product("Phone",855)
product2 = Product("Earphone", 50)
product3 = Product("Charger", 9)

order1 = Order()
order1.add_product(product2)
order1.add_product(product3)

order2 = Order()
order2.add_product(product1)

cus= Customer("Alex")

cus.order_place(order1)
cus.get_order_summary()

