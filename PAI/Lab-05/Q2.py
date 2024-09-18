from abc import ABC, abstractmethod

class shape(ABC):
    @abstractmethod
    def area(self):
        print("Base")
        
class rectangle(shape):
    def area(self, h, b):
        print(f"The area of rectange is {h*b}")
        
class triangle(shape):
    def area(self, h, b):
        print(f"The area of triangle is {0.5*b*h}")
        
class square(shape):
    def area(self, l):
        print(f"The area of square is {l*l}")
        
r = rectangle()
r.area(4,5)

t = triangle()
t.area(4,5)

s = square()
s.area(3)
