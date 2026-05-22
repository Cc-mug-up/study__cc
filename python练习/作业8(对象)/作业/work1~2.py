class BMI(object):
    def __init__(self,weight,height):
        self.weight=float(weight)
        self.height=float(height)
        self.BMIIndex=weight/height/height
    def printBMI(self):
        print("BMI 为 {0:.1f}".format(self.BMIIndex))
class ChinaBMI(BMI):
    def printBMI(self):
        if self.BMIIndex < 18.5:
            print("BMI指数: {0:.1f} , BMI分类: 偏瘦 , 相关疾病危险性: 低(但其他疾病危险性增加)".format(self.BMIIndex))
        elif self.BMIIndex < 23.9:
            print("BMI指数: {0:.1f} , BMI分类: 正常 , 相关疾病危险性: 平均水平".format(self.BMIIndex))
        elif self.BMIIndex < 26.9:
            print("BMI指数: {0:.1f} , BMI分类: 偏胖 , 相关疾病危险性: 增加".format(self.BMIIndex))
        elif self.BMIIndex < 29.9:
            print("BMI指数: {0:.1f} , BMI分类: 肥胖 , 相关疾病危险性: 中度增加".format(self.BMIIndex))
        else:
            print("BMI指数: {0:.1f} , BMI分类: 重度肥胖 , 相关疾病危险性: 严重增加".format(self.BMIIndex))
if __name__ == "__main__":
    B1=ChinaBMI(60,1.82)
    B1.printBMI()
    B1=ChinaBMI(69,1.79)
    B1.printBMI()
    B1=ChinaBMI(82,1.78)
    B1.printBMI()
    B1=ChinaBMI(85,1.75)
    B1.printBMI()
    B1=ChinaBMI(95,1.77)
    B1.printBMI()