#! /usr/bin/python

import sys

def find_eariest_round(user_index, name, max_score):
    for score, round in user_index[name]:
        if score >= max_score:
            return round

if __name__ == '__main__':
    sys.stdin.readline()
    score_info = {}
    user_index = {}
    round = 0
    for line in sys.stdin.readlines():
        name, score = line.split()
        score = int(score)
        score_info[name] = score_info.get(name, 0) + score
        if score > 0:
            if name not in user_index:
                user_index[name] = []
            user_index[name].append( (score_info[name], round))
        round += 1

    max_score = max(score_info.values())
    candidates = filter(lambda k: score_info[k] == max_score, score_info.keys())
    r = map(lambda name: (name, find_eariest_round(user_index, name, max_score)), candidates)
    r.sort(lambda x, y: x[1] - y[1])
    print r[0][0]
