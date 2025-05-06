class SetADT:
    def __init__(self):
        self.elements = []

    def add(self, element):
        if element not in self.elements:
            self.elements.append(element)

    def remove(self, element):
        if element in self.elements:
            self.elements.remove(element)

    def contains(self, element):
        return element in self.elements

    def size(self):
        return len(self.elements)

    def iterator(self):
        return iter(self.elements)

    def intersection(self, other_set):
        result = SetADT()
        for element in self.elements:
            if other_set.contains(element):
                result.add(element)
        return result

    def union(self, other_set):
        result = SetADT()
        for element in self.elements:
            result.add(element)
        for element in other_set.elements:
            result.add(element)
        return result

    def difference(self, other_set):
        result = SetADT()
        for element in self.elements:
            if not other_set.contains(element):
                result.add(element)
        return result

    def is_subset(self, other_set):
        for element in self.elements:
            if not other_set.contains(element):
                return False
        return True

    def __str__(self):
        return "{" + ", ".join(str(e) for e in self.elements) + "}"


# Example usage
if __name__ == "__main__":
    A = SetADT()
    B = SetADT()

    for x in [1, 2, 3, 4]:
        A.add(x)
    for x in [3, 4, 5, 6]:
        B.add(x)

    print("Set A:", A)
    print("Set B:", B)
    print("Intersection:", A.intersection(B))
    print("Union:", A.union(B))
    print("Difference A - B:", A.difference(B))
    print("Is A subset of B?", A.is_subset(B))
    print("Is {3, 4} subset of A?", SetADT().union(SetADT()).intersection(B).is_subset(A))
