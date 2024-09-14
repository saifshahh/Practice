class Student:
    def __init__(self,name,id):
        self.name = name
        self.id = id
        
    def get_info(self):
        print(f"Student name is {self.name} having id {self.id}.")
        
class Marks(Student):
    _marks = []
    
    def __init__(self,name,id):
        self.name = name
        self.id = id
        self._marks = []
    
    def CoursesMarks(self):
        a = int(input('Enter the number of courses: '))
        for i in range(a):
            self._marks.append(int(input(f'Enter the marks of {i+1} course: ')))
        
    def show(self):
        print(self._marks)
    
class Result(Marks):
    __total = 0
    def __init__(self,name,id):
        self.name = name
        self.id = id
    
    def calculate(self):
        for i in range(len(self._marks)):
            self.__total += self._marks[i]
            
    def info(self):
        self.avg = self.__total / len(self._marks)
        print(f"Total marks: {self.__total} and Average is: {self.avg}")
        
res = Result('Syed',2300032)
res.get_info()
res.CoursesMarks()
res.show()
res.calculate()
res.info()
