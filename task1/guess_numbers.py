# WSL Python第一个小游戏：猜数字
import random

# 1. 生成1-10之间的随机数
secret_number = random.randint(1, 10)
print("🎮 猜数字小游戏（1-10）")
print("提示：猜对为止，看看你要猜几次～")

# 2. 记录猜测次数
guess_count = 0

# 3. 循环猜数字
while True:
    # 输入数字并处理异常（避免输错格式）
    try:
        user_guess = int(input("请输入你猜的数字："))
        guess_count += 1
        
        # 条件判断
        if user_guess < secret_number:
            print("🔽 太小啦，再往大了猜猜！")
        elif user_guess > secret_number:
            print("🔼 太大啦，再往小了猜猜！")
        else:
            print(f"🎉 恭喜猜对了！你一共猜了 {guess_count} 次～")
            break  # 猜对退出循环
    except ValueError:
        print("❌ 请输入数字哦！别输文字～")# 测试WSL Python环境（通用版，无兼容问题）
