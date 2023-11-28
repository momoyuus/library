import subprocess
import sys
import re
import io
import os
import datetime

sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')

args = sys.argv
if len(args) < 2:
  exit()
buffer = "buf.cpp"

buf = open(buffer, mode='w', encoding='utf-8')
with open(args[1], mode='r', encoding='utf-8') as f:
  lines = f.readlines()
  for line in lines:
    buf.write(line)
    # `#include` 同士は 1 行空ける
    if len(line) > 8 and line[:8] == '#include':
      buf.write('\n')
buf.close()

library_path = os.getcwd()

nw = datetime.datetime.now()
print("/**")
print(" * date   : " + nw.strftime("%Y-%m-%d %H:%M:%S"))
print(" * author : Nyaan")
print(" */")
print()
print("#define NDEBUG")
cmd = ["oj-bundle", "-I", library_path, buffer]
proc = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
if proc.returncode != 0:
  msg = proc.stderr.decode("utf-8").split('\n')
  msg = msg[max(0, len(msg) - 20):]
  print("\n".join(msg), file=sys.stderr)
  print('\033[31m' + 'bundle Failed.' + '\033[0m', file=sys.stderr)
  exit(1)
src = proc.stdout.decode("utf-8")
lines = src.split('\n')

debug_flag = False
trc_ifdef_flag = False
trc2_ifdef_flag = False

for line in lines:
  # namespace DebugImpl を適切に削除
  if re.search('namespace DebugImpl', line):
    debug_flag = not debug_flag
    continue

  # define trc2 からはじまる行を適切に置換
  if re.search('define trc2', line):
    if re.search('void', line) == None:
      assert trc2_ifdef_flag == False
      trc2_ifdef_flag = True
      continue
  if trc2_ifdef_flag == True and re.search('while', line):
    assert trc2_ifdef_flag == True
    trc2_ifdef_flag = False
    print('#define trc2(...) (void(0))')
    continue

  # define trc からはじまる行を適切に置換
  if re.search('define trc', line):
    if re.search('void', line) == None:
      assert trc_ifdef_flag == False
      trc_ifdef_flag = True
      continue
  if trc_ifdef_flag == True and re.search('while', line):
    assert trc_ifdef_flag == True
    trc_ifdef_flag = False
    print('#define trc(...) (void(0))')
    continue

  if debug_flag or trc_ifdef_flag or trc2_ifdef_flag:
    continue

  if not re.match('^#line', line):
    print(line, end='')
  else:
    print()