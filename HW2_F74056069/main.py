import urllib.request
import re
import matplotlib.pyplot as plt
import collections

author = input("Input Author: ")
search_author = author.replace(" ", "+")
search_type = "&searchtype=author"
search_size = 200
url = "https://arxiv.org/search/?query=" + search_author + search_type + "&size=" + str(search_size)
content = urllib.request.urlopen(url)
html_str = content.read().decode('utf-8')

## Get all html content with all page
page_pattern = '<h1 class="title is-clearfix">[\s\S]*?<span class="mathjax">'
page_result = re.findall(page_pattern, html_str)
page_number = int(int(page_result[0].split("of ")[1].split(" results")[0]) / (search_size+1))
html_str = ""
for p in range(0, page_number+1):
	url = "https://arxiv.org/search/?query=" + search_author + search_type + "&size=" + str(search_size) + "&start=" + str(p*search_size)
	content = urllib.request.urlopen(url)
	html_str += content.read().decode('utf-8')

## Question 1
year_pattern = 'originally announced</span>[\s\S]*?</p>'
year_result = re.findall(year_pattern, html_str)
year_dict = dict()	## For store dictionary
for r in year_result:
	year = r.split("</span>")[1].split("</p>")[0].strip().split(" ")[1].split(".")[0]
	if year in year_dict:	## if exist in dictionary, increase the value of this year
		year_dict[year] += 1
	else:	## if not exist, initial it
		year_dict[year] = 1
year_dict = collections.OrderedDict(sorted(year_dict.items())) 	## Sort dictionary by key
## plot the bar graph
plt.bar(range(len(year_dict)), list(year_dict.values()))
plt.xticks(range(len(year_dict)), list(year_dict.keys()))
plt.xlabel('Year')
plt.ylabel('Number of Paper')
plt.title(author)
plt.draw()

## Question 2
author_pattern = 'Authors:</span>[\s\S]*?</p>'
author_result = re.findall(author_pattern, html_str)
author_dict = dict()
for r in author_result:		## First get each paper's authors
	r = r.split("</span>")[1].split("</p>")[0].split(", et al.")[0].strip().split("</a>")
	for co_author in r:	## Second get each co_author
		if co_author != "":		## For remove last empty element by split
			co_author = co_author.split('">')[1].strip()	
			if co_author != author:
				if co_author in author_dict:
					author_dict[co_author] += 1	## For co_author exist in dictionary
				else: 
					author_dict[co_author] = 1	## For co_author not exist in dictionary
author_dict = collections.OrderedDict(sorted(author_dict.items()))
for key in author_dict:
	print(str(key) + ": " + str(author_dict[key]) + " times")

## For prevent thread lock by plt.show()
plt.show()
