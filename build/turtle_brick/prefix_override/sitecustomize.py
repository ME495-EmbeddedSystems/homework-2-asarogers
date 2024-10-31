import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/asaace00/repo/me495/hw2/src/homework2/install/turtle_brick'
