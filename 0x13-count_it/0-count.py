#!/usr/bin/python3
"""
Recursive Suffering
"""

import requests
import json


def count_words(subreddit, word_list=[], count={}, titles=[], counter=0):
    """ top ten posts on a given sub reddit """

    if (count == {}):

        Udata = {'User-Agent': 'JavaPhish 2.0'}
        req_url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
        api = requests.get(req_url, headers=Udata, allow_redirects=False)

        if (api.status_code != 200):
                return

        api = json.loads(api.text)

        # Create an int dictionary containing each word to count occurances
        for word in word_list:
            count[word.lower()] = 0

        # Create list of titles from API call
        for d in api['data']['children']:
            for i in d['data']['title'].split(' '):
                titles.append(i)

    # Checks if we've collected all word occurances and prints them if so
    if (counter >= len(word_list)):
        for c in sorted (count.keys()):
            if (count[c] != 0):
                print("{}: {}".format(c, count[c]))
        return

    word = word_list[counter].lower()
    counter += 1

    # Checks for occurances of current words
    for title in titles:
        if (word.lower() == title.lower()):
            count[word] += 1

    # moves to next word
    count_words(None, word_list, count, titles, counter)
