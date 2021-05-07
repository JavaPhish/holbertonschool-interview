#!/usr/bin/python3
"""
Recursive Suffering
"""

import json
import requests


def make_match_list(subreddit):
    """ Creates a list of all words used """
    Udata = {'User-Agent': 'JavaPhish 2.0'}
    after = ""
    word_bank = []

    # Skim through reddit pages until it returns None (All pages done)
    while (after is not None):
        if (after == ""):
            req_url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
        else:
            req_url = 'https://www.reddit.com/r/{}/hot.json?after={}'.\
                      format(subreddit, after)
        api = requests.get(req_url, headers=Udata, allow_redirects=False)

        # Check if api is happy
        if (api.status_code != 200):
            return
        after = api.json()['data']['after']
        api = json.loads(api.text)

        # Add words from titles to word bank
        for d in api['data']['children']:
            for i in d['data']['title'].split(' '):
                word_bank.append(i)

    return word_bank


def count_words(subreddit, word_list=[], count={}, titles=[], counter=0):
    """ top ten posts on a given sub reddit """

    # Checks if we've populated our word bank of words from titles
    if (titles == []):
        titles = make_match_list(subreddit)
        # print(make_match_list(subreddit))

    # Creates a dictionary of relevent words with integers to count occurances
    if (count == {}):
        for word in word_list:
            count[word.lower()] = 0

    # Print all results if compelted
    if (counter >= len(word_list)):
        count = sorted(count.items(), key=lambda x: (-x[1], x[0]))
        for c in count:
            if (c[1] != 0):
                print("{}: {}".format(c[0], c[1]))
        return

    # keep track of the word we are currently searching/counting
    word = word_list[counter].lower()
    counter += 1

    # Check the word bank for occurances of the current word
    for title in titles:
        if (word.lower() == title.lower()):
            count[word] += 1

    # On to the next word!
    count_words(None, word_list, count, titles, counter)
