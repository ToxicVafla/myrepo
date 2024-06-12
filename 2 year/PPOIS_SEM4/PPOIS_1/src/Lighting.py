from SmartDevice import SmartDevice


class Lighting(SmartDevice):
    brightness_percentage = 100

    def set_brightness(self, percentage):
        self.brightness_percentage = percentage
        print(self.name, "brightness set to", percentage)

    def display_value(self):
        super().display_value()
        print(self.name, "brightness is", self.brightness_percentage, "%")