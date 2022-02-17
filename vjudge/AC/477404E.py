import sys


for input in sys.stdin:
    try:
        [tape_length, num, *track_lengths] = map(int, input.strip().split())
    except Exception:
        break
    # dp[i][j]: 遍历到第 i 个曲目，tape 长度为 j 分钟时最多装多少分钟
    dp = [0] * (tape_length + 10)
    use = [[False] * (tape_length + 10) for x in range(num+1)]
    for i in range(num):
        for j in range(tape_length, track_lengths[i]-1, -1):
            if dp[j-track_lengths[i]]+track_lengths[i] > dp[j]:
                dp[j] = dp[j-track_lengths[i]]+track_lengths[i]
                use[i][j] = True

    tmp = tape_length
    s = []
    for i in range(num-1, -1, -1):
        if use[i][tmp]:
            s.append(track_lengths[i])
            tmp -= track_lengths[i]
    print(*s, sep=' ', end=' ')
    print('sum:'+str(dp[tape_length]))
