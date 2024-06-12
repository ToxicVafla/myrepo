from SmartDevice import SmartDevice


class SmartHouseholdAppliance(SmartDevice):
    type = ""  # cleaning, food
    documentation = []  # "fried eggs", "boiled eggs", "meat", "pasta", "rice", "coffe", "tea", "toast", "pancakes"
    # "dishes", "floor"

    def __init__(self, name, type, documentation):
        super().__init__(name)
        self.type = type
        self.documentation = documentation

    def work(self):
        if self.type == "cleaning":
            print("What do you like to clean?")
            object = input()
            if object in self.documentation:
                print("cleaning ", object)
            else:
                print("Sorry, there is no such object in documentation")
        elif self.type == "food":
            print("What do you like to cook?")
            object = input()
            if object in self.documentation:
                print(object, "is done")
            else:
                print("Sorry, there is no such object in documentation")