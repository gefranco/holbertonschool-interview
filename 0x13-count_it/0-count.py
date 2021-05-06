#!/usr/bin/python3
import requests
import json
import re
import sys
def count_words(subreddit, word_list):
	req = ""
	if not req:
		req = requests.get("http://www.reddit.com/r/{}/hot.json".format(sys.argv[1]), headers = {'User-agent': 'hbtn-933'})
	if req.status_code is not 200:
		return
	json_text = json.loads(req.text)
	# print(json_text["data"]["children"][0]["data"]["title"])
	# print(json_text["data"]["children"])
	count(json_text["data"]["children"], 0, word_list, 0, 0)
	return 0


def count(json, index, word_list, index_words, word_count):
	# print(str(len(json)) + " : " + str(index))
	# print(str(len(word_list)) + " : " + str(index_words))
	# print(word_list[index_words])
	if index_words  >= len(word_list):
		return
	if index >= len(json):
		if word_count > 0:
			print(word_list[index_words] +": " + str(word_count))
		return count(json, 0, word_list, index_words + 1, 0)
	if re.search(r'\b' + word_list[index_words] + r'\b', json[index]["data"]["title"], re.IGNORECASE):
	# if word_list[index_words] in json[index]["data"]["title"]:
		# print(word_list[index_words] + " : " + json[index]["data"]["title"])
		word_count += 1
	return count(json, index + 1, word_list, index_words, word_count)
	
