#!/bin/bash

# 自动提交代码到GitHub的脚本

# 设置颜色输出
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# 检查是否在git仓库中
if ! git rev-parse --git-dir > /dev/null 2>&1; then
    echo -e "${RED}错误：当前目录不是一个git仓库${NC}"
    exit 1
fi

# 获取提交信息（如果没有提供参数，使用默认信息）
COMMIT_MESSAGE="${1:-Update code $(date '+%Y-%m-%d %H:%M:%S')}"

echo -e "${YELLOW}开始提交代码...${NC}"

# 添加所有文件到暂存区
echo "正在添加文件..."
git add .

# 检查是否有文件需要提交
if git diff --cached --quiet; then
    echo -e "${YELLOW}没有需要提交的文件${NC}"
    exit 0
fi

# 提交代码
echo "正在提交代码..."
git commit -m "$COMMIT_MESSAGE"

if [ $? -ne 0 ]; then
    echo -e "${RED}提交失败${NC}"
    exit 1
fi

# 推送到远程仓库
echo "正在推送到GitHub..."
GIT_HTTP_TIMEOUT=10 git push -v

if [ $? -eq 0 ]; then
    echo -e "${GREEN}代码提交成功！${NC}"
    read -p "按任意键继续..."
else
    echo -e "${RED}推送失败，请检查网络连接或远程仓库配置${NC}"
    read -p "按任意键继续..."
    exit 1
fi