#!/usr/bin/python3
"""
queries the Reddit API,
parses the title of all hot articles
and prints a sorted count of given keywords
"""
import requests
import json
import re
import sys


def count_words(subreddit, word_list):
    """
    request to reddit api
    """
    req = requests.get(
        "http://www.reddit.com/r/{}/hot.json?count=1000".format(sys.argv[1]),
        headers={'User-agent': 'hbtn'})
    if req.status_code is not 200:
        return
    json_text = json.loads(req.text)
    # print(json_text["data"]["children"][0]["data"]["title"])
    count(json_text["data"]["children"], 0, word_list, 0, 0)
    return 0


def count(json, index, word_list, index_words, word_count):
    """
    recursivly count the words from a title from a json
    """
    c = 0
    if index_words >= len(word_list):
        return
    if index >= len(json):
        if word_count > 0:
            print(word_list[index_words] + ": " + str(word_count))
        return count(json, 0, word_list, index_words + 1, 0)
    #c = re.search(
    #        r'\b' + word_list[index_words] + r'\b',
    #        json[index]["data"]["title"], re.IGNORECASE)
        # if word_list[index_words] in json[index]["data"]["title"]:
        # print(word_list[index_words] + " : " + json[index]["data"]["title"])
    c = [x.lower() for x in json[index]["data"]["title"].split()].count(word_list[index_words].lower())
    # print([x.lower() for x in json[index]["data"]["title"].split()])
    if c > 0:
        word_count += c
    return count(json, index + 1, word_list, index_words, word_count)
