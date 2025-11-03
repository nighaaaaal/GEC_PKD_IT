#a) Scrap HTML content from a page and pass the code with beautiful soup.

import requests
from bs4 import BeautifulSoup
def  scrape_webpage(url):
    response=requests.get(url)
    if response.status_code==200:
        soup=BeautifulSoup(response.content,'html.parser')
        return soup
    else:
        print(f"There is an error connecting to the site with code: {response.status_code}")
        return None
def extract_data(soup):
    headings=soup.find_all(['h1','h2','h3'])
    for heading in headings:
        print(heading.get_text(strip=True))
url="https://gecskp.ac.in"
soup=scrape_webpage(url)
if soup:
    extract_data(soup)