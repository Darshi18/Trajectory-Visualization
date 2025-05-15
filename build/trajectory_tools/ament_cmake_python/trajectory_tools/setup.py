from setuptools import find_packages
from setuptools import setup

setup(
    name='trajectory_tools',
    version='0.0.1',
    packages=find_packages(
        include=('trajectory_tools', 'trajectory_tools.*')),
)
