from SmartDevice import SmartDevice


class HumiditySystem(SmartDevice):
    humidity = 40

    def set_humidity(self, humidity):
        self.humidity = humidity
        print(self.name, "humidity set to", self.humidity)

    def display_value(self):
        super().display_value()
        print(self.name, "humidity is", self.humidity, "%")