import os


def get_home_dir():
    return os.path.expanduser("~")


APP_NAME = "app"

HOME_DIR = get_home_dir()
DEV_DIR = os.path.join(HOME_DIR, "dev")
DEP_DIR = os.path.join(DEV_DIR, ".dependencies", APP_NAME)
CONF_DIR = os.path.join(DEV_DIR, ".config", APP_NAME)
