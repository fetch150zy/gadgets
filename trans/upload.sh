#! /usr/bin/bash

cd trans-client &&
python setup.py sdist bdist_wheel &&
twine upload dist/* --verbose &&
cd ..