class User:
    def __init__(self,name,email):
        self.name = name
        self.email = email
        self.friends = []
        self.request = []
    def send_friend_request(self,other_user):
        if other_user not in self.friends and self != other_user and self != other_user.request:
            other_user.request.append(self)
            print(f"{self.name} sent a friend request to {other_user.name}.")
    def accept_friend_request(self,other_user):
        if other_user in self.request:
            self.friends.append(other_user)
            other_user.friends.append(self)
            self.request.remove(other_user)
            print(f"{self.name} accepted {other_user.name} request")
    def show_friend_list(self):
        if self.friends:
            print(f"{self.name} is: {[user.name for user in self.friends]}")
        else:
            print(f"{self.name} has no friends yet!")

user1 = User("Harry","harry.02@gmail.com")
user2 = User("Jack","jack.03@gmail.com")

user1.send_friend_request(user2)
user2.accept_friend_request(user1)
user2.show_friend_list()
user1.show_friend_list()