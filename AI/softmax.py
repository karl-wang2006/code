import torch
from torch import nn
from d2l import torch as d2l

# 通用测试准确率计算函数
def evaluate_accuracy(net, data_iter):
    net.eval()
    correct = 0
    total = 0    
    with torch.no_grad():        
        for X, y in data_iter:
            y_hat = net(X)
            pred = y_hat.argmax(dim=1)
            correct += (pred == y).sum().item()
            total += y.shape[0]    
    return correct / total

# 导入训练集和测试集数据，一次导入256个
batch_size = 256
train_iter , test_iter = d2l.load_data_fashion_mnist(batch_size)

# PyTorch不会隐式地调整输入的形状。因此，
# 我们在线性层前定义了展平层（flatten），来调整网络输入的形状
net = nn.Sequential(nn.Flatten(), nn.Linear(784,10))
# sequetial- 自动把网络排序好，自动向前传播。数据会先展平，后计算线性值o
# flatten - 自动展平输入张量，从第二维展平到最后一维（N,1,28,28)->(N,1*28*28)
# Linear - 自动计算线性输出，输入维度784，输出维度为10，自动维护 W，b
# net - 就是我们搭建的神经网络，第一层是Flatten，没有参数，只负责展平数据张量；第2层是Linear，
# 有参数，负责线性计算与参数传递更新。

# 现在手动进行权重 W 的初始化，m代表一个线性神经网络层

def init_weight(m):    
    if type(m) == nn.Linear:
        nn.init.normal_(m.weight, std = 0.01)

 # 遍历每一个net里的层，进行 W 的初始化
net.apply(init_weight)

# 创建交叉熵损失函数（none表示返回每一个样本的独立的值）
loss = nn.CrossEntropyLoss(reduction='none')

# 创建优化器，用于更新参数 W,b
trainer = torch.optim.SGD(net.parameters(),lr=0.1)

# 确定训练轮次
num_epoch = 10
for epoch in range(num_epoch):    
    for X, y in train_iter:
        y_hat = net(X) # 向前传播计算预测值
        l = loss(y_hat,y) # 计算交叉熵损失
        trainer.zero_grad() # 梯度清零，torch是叠加梯度的，要手动清零以免梯度污染
        l.mean().backward() # 计算批量的平均损失，再反向传播求梯度
        trainer.step() #更新参数

    # 每一轮结束，评估测试集准确率
    test_acc = evaluate_accuracy(net, test_iter)    
    print(f"第 {epoch+1} 轮 | 测试集准确率: {test_acc:.4f}")