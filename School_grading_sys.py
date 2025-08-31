from pickletools import markobject


class Grading_system:
    def __init__(self,name,mark):
        self.name = name
        self.mark = mark
    def calculate_grade(self):
        if not self.mark:
            return "No marks available"
        average = sum(self.mark.values()) / len(self.mark)
        if average >= 90:
            return "A"
        elif average >= 80:
            return "B"
        elif average >= 70:
            return "C"
        elif average >= 60:
            return "D"
        else:
            return "E"


std1 =Grading_system("Yiting",{"Computer" : 88,"Discrete math":93})

print(f"Student name: {std1.name}, Average: {std1.calculate_grade()}")