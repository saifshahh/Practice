def fcfs(processes):
    n = len(processes)
    wt = [0] * n
    tat = [0] * n

    # Waiting time
    for i in range(1, n):
        wt[i] = wt[i-1] + processes[i-1][1]

    # Turnaround time = WT + BT
    for i in range(n):
        tat[i] = wt[i] + processes[i][1]

    avg_wt = sum(wt) / n
    avg_tat = sum(tat) / n

    print("Process\tBT\tWT\tTAT")
    for i in range(n):
        print(f"P{processes[i][0]}\t{processes[i][1]}\t{wt[i]}\t{tat[i]}")

    print(f"\nAverage Waiting Time = {avg_wt}")
    print(f"Average Turnaround Time = {avg_tat}")

# Format: (Process ID, Burst Time)
processes = [(1, 5), (2, 3), (3, 8)]
fcfs(processes)
