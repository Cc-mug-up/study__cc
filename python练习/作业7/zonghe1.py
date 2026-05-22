# Filename: prog7-3.py
def f(listdata, n, flag='max'):
    m = listdata[0][n]
    if flag == 'max':
        for item in listdata:
            if item[n] > m:
                m = item[n]
    elif flag == 'min':
        for item in listdata:
            if item[n] < m:
                m = item[n]
    elif flag == 'ave':
        m = 0
        for item in listdata:
            m += item[n]
        m /= len(listdata)
    return m

def stas(x, field):
    print(' {:5s} {:5s} {:5s}'.format(field[1], field[2], field[3]))
    print('最高分:{:5d}{:5d}{:5d}'.format(f(x, 1), f(x, 2), f(x, 3)))
    print('最低分:{:5d}{:5d}{:5d}'.format(f(x, 1, 'min'), f(x, 2, 'min'), f(x, 3, 'min')))
    print('平均分:{:5.1f}{:5.1f}{:5.1f}'.format(f(x, 1, 'ave'), f(x, 2, 'ave'), f(x, 3, 'ave')))

if __name__ == "__main__":
    with open(r"D:\86189\vscode\python练习\作业7\score.txt", 'r+', encoding='gbk') as fp:
        lines = fp.readlines()
        field = lines.pop(0).split(',')
        x = []
        for eachline in lines:
            t = eachline.split(',')
            for j in range(1, len(t)):
                t[j] = int(t[j])
            x.append(t)
        stas(x, field)
        for i in range(len(x)):
            lines[i] = lines[i].strip() + ',' + str(x[i][1] + x[i][2] + x[i][3]) + '\n'
        field[-1] = field[-1].strip()
        field.append('总分\n')
        lines.insert(0, ','.join(field))
        print(lines)
        fp.seek(0)
        fp.writelines(lines)
        fp.truncate()  # 确保文件被正确截断