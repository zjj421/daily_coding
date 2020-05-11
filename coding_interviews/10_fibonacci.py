import datetime


# 递归
def fibonacci_recursive(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2)


# 遍历
def fibonacci(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    fib_1 = 1
    fib_2 = 0
    fib_n = -1
    for i in range(2, n + 1):
        fib_n = fib_1 + fib_2
        fib_2 = fib_1
        fib_1 = fib_n
    return fib_n


def test_fibonacci():
    n = 100
    starttime = datetime.datetime.now()
    fib_n = fibonacci_recursive(n)
    duration = (datetime.datetime.now() - starttime).microseconds

    print('fibonacci_recursive({}) = {}, time: {} us'.format(n, fib_n, duration))

    starttime = datetime.datetime.now()
    fib_n = fibonacci(n)
    duration = (datetime.datetime.now() - starttime).microseconds

    print('fibonacci({}) = {}, time: {} us'.format(n, fib_n, duration))


if __name__ == '__main__':
    test_fibonacci()
