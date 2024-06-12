from SmartDevice import SmartDevice


class TemperatureDevice(SmartDevice):
    temperature = 20

    def set_temperature(self, temperature):
        self.temperature = temperature
        print(self.name, "temperature set to", self.temperature)

    def display_value(self):
        super().display_value()
        print(self.name, "temperature is", self.temperature, "degrees Celsius")