#!/usr/bin/env python3
import sys
import requests
from datetime import datetime, timezone, timedelta

# adjust this if your local offset changes (e.g. DST)
USER_TZ = timezone(timedelta(hours=-3))

def get_daily_stats(handle: str, date_str: str):
    """
    Returns three things for the given user and date:
      - solved: dict mapping "contestId-index" → (name, rating)
      - attempted: dict mapping "contestId-index" → (name, rating)
      - tags: set of all tags across those problems
    date_str should be "YYYY-MM-DD" (interpreted in YOUR local timezone).
    """
    # build timestamp window for YOUR local day
    date = datetime.strptime(date_str, '%Y-%m-%d').date()
    start_local = datetime(date.year, date.month, date.day, tzinfo=USER_TZ)
    end_local   = start_local + timedelta(days=1)
    start_ts = int(start_local.timestamp())
    end_ts   = int(end_local.timestamp())

    # pull your submission history
    url = f'https://codeforces.com/api/user.status?handle={handle}&from=1&count=100000'
    resp = requests.get(url)
    resp.raise_for_status()
    data = resp.json()
    if data['status'] != 'OK':
        raise RuntimeError(f"CF API error: {data.get('comment','<no comment>')}")

    solved    = {}
    attempted = {}
    tags      = set()

    for sub in data['result']:
        t = sub['creationTimeSeconds']
        if t < start_ts or t >= end_ts:
            continue

        prob   = sub['problem']
        pid    = f"{prob['contestId']}-{prob['index']}"
        name   = prob['name']
        rating = prob.get('rating')   # may be None for unrated/gym

        # record attempt
        attempted[pid] = (name, rating)
        tags.update(prob.get('tags', []))

        # if solved, record it too
        if sub.get('verdict') == 'OK':
            solved[pid] = (name, rating)

    return solved, attempted, tags

def main():
    if len(sys.argv) != 2:
        print(f"Usage: python {sys.argv[0]} YYYY-MM-DD")
        sys.exit(1)
    date_str = sys.argv[1]
    handle   = "becastal"

    solved, attempted, tags = get_daily_stats(handle, date_str)

    print(f"Estudos pessoais em {date_str}\n")

    print("Problemas estudados:")
    for pid in sorted(attempted):
        name, rating = attempted[pid]
        rating_str = f" ({rating})" if rating is not None else ""
        print(f"  {pid}: {name}{rating_str}")

if __name__ == '__main__':
    main()
