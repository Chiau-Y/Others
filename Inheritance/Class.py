# Class
class Phone:
    
    def __init__(self, os, number, is_waterproof):
        self.os = os
        self.number = number
        self.is_waterproof = is_waterproof
        
    def Specification(self):
        print("This Phone is the number -", self.number, ", os is", self.os, ", and it is", "waterproof" if (self.is_waterproof) else "not waterproof")
                
    def Set_Waterproof(self, newwaterproof):
        self.is_waterproof = newwaterproof
# ------------------------------------ Main ---------------------------------- #
if __name__ == '__main__':    
    
    phone1 = Phone("ios", 1, True)
    phone1.Specification()
    
    phone2 = Phone("android", 2, False)
    phone2.Specification()
    
    phone2.Set_Waterproof(True)
    phone2.Specification()