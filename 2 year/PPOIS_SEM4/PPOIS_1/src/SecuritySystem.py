from SmartDevice import SmartDevice
import time


class SecuritySystem(SmartDevice):  # надо сделать так, что выводит уведомления из главного класса о покрытии зон
    charge_value = 20
    device_type = ""  # breakIn, fire
    covering_area = 0  # there are 3 zones

    def __init__(self, name, device_type, covering_area):
        super().__init__(name)
        self.device_type = device_type
        self.covering_area = covering_area

    def charge(self):
        while self.charge_value <= 90:
            self.charge_value += 10
            time.sleep(1)
            print("charging...", self.charge_value)
        self.security_check()

    def security_check(self):
        if not self.status:
            print("\033[31m{}".format("Don't forget to turn on"), self.name, "\033[0m{}".format(""))

    def alarm(self):
        if self.device_type == "breakIn":
            print("Alarm. Police called!")
        elif self.device_type == "fire":
            print("Alarm. Firefighters called!")
        print("How much people are injured?")
        if int(input()) > 0:
            print("Ambulance called")
