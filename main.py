import asyncio
import random

# 模拟异步获取数据
async def fetch_data(url):
    print(f"Start fetching {url}...")
    
    # 模拟异步 I/O 操作，等待一个随机时间来模拟网络延迟
    await asyncio.sleep(random.randint(1, 5))  # 随机等待 1 到 3 秒钟
    
    # 模拟数据获取完成
    data = f"Data from {url}"
    print(f"Done fetching {url}")
    return data

# 主程序
async def main():
    # 定义多个 URL
    urls = ["http://example.com", "http://example.org", "http://example.net", "http://example.edu"]

    # 创建多个异步任务并发执行
    tasks = [fetch_data(url) for url in urls]
    print("\nMain thread...")
    # 等待所有任务完成，并获取它们的结果
    results = await asyncio.gather(*tasks)
    print("\nMain thread2...")
    # 输出所有请求结果
    print("\nAll requests completed!")
    for result in results:
        print(result)

# 执行主程序
asyncio.run(main())
