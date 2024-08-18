import os
import json
from coloring import Color, colorize

def get_home_dir():
    return os.path.expanduser("~")

TEST = False

APP_NAME = "[[name]]"

HOME_DIR: str
CWD: str
LOC_FILE: str
DEP_DIR: str
CONF_DIR: str

def update():
    global HOME_DIR, CWD, LOC_FILE, DEP_DIR, CONF_DIR
    HOME_DIR = get_home_dir()
    CWD = os.getcwd()
    LOC_FILE = os.path.join(HOME_DIR, ".loc.json")
    DEP_DIR = os.path.join(CWD, "dependencies")
    CONF_DIR = os.path.join(CWD, "config")
    if os.path.exists(LOC_FILE) and TEST is False:
        with open(LOC_FILE, "r") as f:
            loc = json.load(f)
            DEP_DIR = os.path.join(loc["dependencies"], APP_NAME)
            CONF_DIR = os.path.join(loc["config"], APP_NAME)
    else:
        print(colorize("using test values ...", Color.YELLOW))
