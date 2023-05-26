class Solution:
    def convertTemperature(self, celsius: float) -> List[float]:
        kel = celsius + 273.15
        fah = celsius * 1.8 + 32
        return [kel , fah]
