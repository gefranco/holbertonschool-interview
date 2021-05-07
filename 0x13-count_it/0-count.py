#!/usr/bin/python3
"""
queries the Reddit API,
parses the title of all hot articles
and prints a sorted count of given keywords
"""
import json
import operator
import re
import requests
import sys


def count_words(subreddit, word_list, after=None, dic={}):
    """
    request to reddit api
    """
    if not dic:
        for word in word_list:
            dic.update({word.lower(): 0})
    req = requests.get(
        "http://www.reddit.com/r/{}/hot.json?after={}".format(
            sys.argv[1], after),
        headers={'User-agent': 'hbtn'})
    if req.status_code is not 200:
        return
    json_text = json.loads(req.text)
    if json_text["data"]["after"] is None:
        count(json_text["data"]["children"], 0, word_list, 0, 0, dic)
        sorted_dic = sorted(dic.items(),
                            key=operator.itemgetter(1), reverse=True)
        for value in sorted_dic:
            if value[1] > 0:
                print(value[0] + ": " + str(value[1]))
        return
    count(json_text["data"]["children"], 0, word_list, 0, 0, dic)
    return count_words(subreddit, word_list, json_text["data"]["after"], dic)


def count(json, index, word_list, index_words, word_count, dic):
    """
    recursivly count the words from a title from a json
    """
    c = word_count
    if index_words >= len(word_list):
        return
    if index >= len(json):
        return count(json, 0, word_list, index_words + 1, 0, dic)
    c = [x for x in json[index]["data"]["title"].lower().split()].count(
        word_list[index_words].lower())
    if c > 0:
        word_count += c
        dic.update(
            {word_list[index_words].lower():
                dic[word_list[index_words].lower()] + c})
    return 
# count(json, index + 1, word_list, index_words, word_count, dic)
