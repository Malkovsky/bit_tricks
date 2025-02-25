#!/usr/bin/env python

import os

def main():
    groups = {
        "Count bits set": [],
        "Reverse": [],
        "Select": [],
        "LSB": [],
        "Division": []
    }
    cols = [
        "name",
        "real_time",
        "cpu_time",
        "time_unit",
        "iterations"
    ]
    with open("build/bm_report.csv") as f:
        for line in f:
            splitted = line.split(',')
            if len(splitted) < 5:
                continue
            if splitted[0] == "name":
                splitted = {splitted[i]: i for i in range(len(splitted))}
                cols_id = {
                    col: splitted[col] for col in cols
                }
            else:
                for key in groups:
                    if splitted[cols_id["name"]].find(key) != -1:
                        groups[key].append(
                            [splitted[cols_id[key]] for key in cols]
                        )

    lines = []
    bt_line = "# Benchmarks"
    with open("README.md") as f:
        for line in f:
            if line.rstrip(os.linesep) == bt_line:
                break
            lines.append(line)
    lines.append(bt_line)
    with open("README.md", "w") as f:
        for line in lines:
            print(line, file=f)
        for key, group in groups.items():
            print(f"## {key}", file=f)
            print("|Benchmark|Time|CPU Time|Iters|", file=f)
            print("|:--------|---:|-------:|----:|", file=f)
            for item in group:
                print(f"|{item[0]}|{item[1]} {item[3]}|{item[2]} {item[3]}|{item[4]}|", file=f)


if __name__ == "__main__":
    main()