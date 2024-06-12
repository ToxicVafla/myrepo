from TemperatureDevice import TemperatureDevice
from HumiditySystem import HumiditySystem
from Lighting import Lighting
from SmartHouseholdAppliance import SmartHouseholdAppliance
from SecuritySystem import SecuritySystem
from SmartDevice import SmartDevice
from Schedule import Schedule
from datetime import datetime, time


class SmartHome:
    security_systems = []
    schedules = []

    def __init__(self, devices):
        self.devices = devices
        print("Smart home created")

    def add_smart_device(self, device):
        if isinstance(device, SmartDevice):  # если device является экземляром класс или его подклассов
            self.devices.append(device)
            print(device.name, "added to smart home")
            if isinstance(device, SecuritySystem):
                self.security_systems.append(device)
        else:
            print("There is no such smart device")

    def list_devices(self):
        if not self.devices:
            print("There is no smart devices at home")
        else:
            print("Smart devices at home:")
            print("-----------")
            for device in self.devices:
                device.display_value()
            print("-----------")

    def create_schedule(self, name, scheduled_time):
        device = self.get_device_by_name(name)
        if device:
            # list functions
            schedule_methods = [method for method in dir(device) if callable(getattr(device, method)) and not method.startswith("__")]
            print(f"Choose a function of {name}:")
            for i, method in enumerate(schedule_methods):
                print(f"{i + 1}. {method}")

            # choose device function
            choice = int(input("Enter the number of the function to execute: ")) - 1
            if 0 <= choice < len(schedule_methods):
                action = getattr(device, schedule_methods[choice])
                schedule = Schedule(action, scheduled_time)
                self.schedules.append(schedule)
            else:
                print("No such function")
        else:
            print(f"Device '{name}' not found")

    def run_schedules(self):
        current_time = datetime.now().time()
        for schedule in self.schedules[:]:  # делаем срез списка, чтобы при удалении элемента списка не ломалась итерация
            if schedule.is_time_to_run(current_time):
                print("Executing schedule")
                schedule.action()
                print("Schedule is done")
                self.schedules.remove(schedule)
            else:
                print("it is not time yet for this action:")
                schedule.display_schedule()

    def display_schedules(self):
        if not self.schedules:
            print("No schedules")
        else:
            print("Schedules:")
            print("-----------")
        for schedule in self.schedules:
            schedule.display_schedule()
        print("-----------")

    def check_security_systems(self):
        for device in self.security_systems:
            device.security_check()
        print("Security systems check is done")

    def get_device_by_name(self, name):  # get device by name to control specific device through home class
        for device in self.devices:
            if device.name == name:
                return device
        return None

    def control_device(self, name):  # control device from SmartHome class so to not calling examples of device's class
        device = self.get_device_by_name(name)
        if device:
            # list functions
            methods = [method for method in dir(device) if callable(getattr(device, method)) and not method.startswith("__")]
            print(f"Choose a function of {name}:")
            for i, method in enumerate(methods):
                print(f"{i + 1}. {method}")

            # choose device function
            choice = int(input("Enter the number of the function to execute: ")) - 1
            if 0 <= choice < len(methods):
                method_to_call = getattr(device, methods[choice])
                method_to_call()
            else:
                print("No such function")
        else:
            print(f"Device '{name}' not found")


Home = SmartHome([Lighting("night light 1"), SecuritySystem("camera 1", "fire", 1)])

Home.add_smart_device(SmartHouseholdAppliance("coffeemachine 1", "food", ["latte", "espresso", "capuchino"]))

Home.list_devices()

Home.add_smart_device(SecuritySystem("camera 2", "breakIn", 2))

Home.create_schedule("camera 2", time(8, 50))
Home.create_schedule("camera 2", time(20, 30))

Home.display_schedules()

Home.run_schedules()

Home.display_schedules()

Home.check_security_systems()

Home.control_device("coffeemachine 1")