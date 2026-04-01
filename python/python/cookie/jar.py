class Jar:
    def __init__(self, capacity=12):
        if type(capacity) != int or capacity < 0:
            raise ValueError("Capacity is not an non-negative integer")
        else:
            self._capacity = capacity
        self._size = 0

    def __str__(self):
        cookie = "🍪"
        return cookie * self.size

    def deposit(self, n):
        if n > self.capacity - self.size:
            raise ValueError("Too many cookie deposited")
        else:
            self._size = self.size + n

    def withdraw(self, n):
        if self._size - n < 0:
            raise ValueError("No enough cookie")
        else:
            self._size = self._size - n

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._size
    
def main():
    jar = Jar(10)
    jar.deposit(2)
    print(jar)
    jar.withdraw(1)
    print(jar)

if __name__ == "__main__":
    main()