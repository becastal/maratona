#!/usr/bin/env python3
import sys
import requests
from datetime import datetime, timezone, timedelta

# Your local timezone (America/Sao_Paulo, UTC−3)
USER_TZ = timezone(timedelta(hours=-3))

# Endpoints
SUBMISSIONS_API = (
    "https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions"
)
MERGED_PROBLEMS = (
    "https://kenkoooo.com/atcoder/resources/merged-problems.json"
)

def load_problem_metadata():
    """Fetch title/difficulty (and any tags) for all AtCoder problems."""
    resp = requests.get(MERGED_PROBLEMS)
    resp.raise_for_status()
    data = resp.json()
    meta = {}
    for p in data:
        # p['id'] is like "abc300_a"
        meta[p["id"]] = {
            "title": p.get("title", ""),
            "difficulty": p.get("difficulty"),
            "tags": p.get("tags", []),
        }
    return meta

def get_daily_stats(user: str, date_str: str):
    # Build [start_ts, end_ts) in UTC from your local midnight
    date = datetime.strptime(date_str, "%Y-%m-%d").date()
    start_local = datetime(date.year, date.month, date.day, tzinfo=USER_TZ)
    end_local = start_local + timedelta(days=1)
    start_ts = int(start_local.timestamp())
    end_ts   = int(end_local.timestamp())

    # Fetch problem metadata
    problem_meta = load_problem_metadata()

    # Fetch all submissions ≥ start_ts (up to 500)
    resp = requests.get(
        SUBMISSIONS_API,
        params={"user": user, "from_second": start_ts},
    )
    resp.raise_for_status()
    subs = resp.json()

    solved = {}
    attempted = {}
    tags = set()

    for s in subs:
        t = s["epoch_second"]
        if t < start_ts or t >= end_ts:
            continue

        pid = s["problem_id"]            # e.g. "abc300_a"
        info = problem_meta.get(pid, {})
        title = info.get("title", pid)
        diff  = info.get("difficulty")   # might be None
        ts    = info.get("tags", [])

        # record attempt
        attempted[pid] = (title, diff)
        tags.update(ts)

        # record solve if AC
        if s.get("result") == "AC":
            solved[pid] = (title, diff)

    return solved, attempted, tags

def main():
    if len(sys.argv) != 2:
        print(f"Usage: python {sys.argv[0]} YYYY-MM-DD")
        sys.exit(1)

    user     = "becastal"
    date_str = sys.argv[1]
    solved, attempted, tags = get_daily_stats(user, date_str)

    print(f"\nMonitoria + Estudos pessoais em {date_str}\n")

    print("Problemas estudados:")
    for pid in sorted(attempted):
        title, diff = attempted[pid]
        diff_str = f" [{diff}]" if diff is not None else ""
        print(f"  {pid}: {title}{diff_str}")

    print("\nProblemas resolvidos:")
    for pid in sorted(solved):
        title, diff = solved[pid]
        diff_str = f" [{diff}]" if diff is not None else ""
        print(f"  {pid}: {title}{diff_str}")

    print("\nAssuntos estudados:")
    if tags:
        for tag in sorted(tags):
            print(f"  {tag}")
    else:
        print("  (nenhuma tag disponível para AtCoder)")

if __name__ == "__main__":
    main()
