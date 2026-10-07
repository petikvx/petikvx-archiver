import sys,struct
d=open(sys.argv[1],'rb').read()
VA0=0x140000000
secs=[('.rdata',0x33000,0x31e00,0x2400)]
def pr(c): return 32<=c<127
hits=[]
for nm,va,rp,rs in secs:
    sec=d[rp:rp+rs]
    for off in range(len(sec)):
        # word mode
        if off+2*6<=len(sec):
            w=[struct.unpack_from('<H',sec,off+2*k)[0] for k in range(min(400,(len(sec)-off)//2))]
            for c0 in range(32,127):
                C=w[0]^c0
                s=[]
                for k,x in enumerate(w):
                    v=x^((C*(k+1))&0xFFFF)
                    if v==0 or not pr(v): break
                    s.append(chr(v))
                if len(s)>=9 and (C!=0): hits.append((len(s),nm,off,'W',C,''.join(s)))
        # byte mode
        if off+6<=len(sec):
            b=sec[off:off+400]
            for c0 in range(32,127):
                C=b[0]^c0
                s=[]
                for k,x in enumerate(b):
                    v=x^((C*(k+1))&0xFF)
                    if v==0 or not pr(v): break
                    s.append(chr(v))
                if len(s)>=9 and C!=0: hits.append((len(s),nm,off,'B',C,''.join(s)))
hits.sort(key=lambda h:(h[1],h[2]))
# drop hits contained in a longer hit at overlapping offsets
out=[]
for h in sorted(hits,key=lambda h:-h[0]):
    span=(h[2],h[2]+h[0]*(2 if h[3]=='W' else 1))
    if any(o[1]==h[1] and not(span[1]<=o[2] or span[0]>=o[3]) for o in [(0,x[1],x[2],x[2]+x[0]*(2 if x[3]=='W' else 1)) for x in out]): continue
    out.append(h)
out.sort(key=lambda h:(h[1],h[2]))
for l,nm,off,m,C,t in out:
    print(f'{nm}+{off:#x} VA {0x140000000+(0x33000 if nm=="rdata" else 0)}'.replace('rdata','.rdata') if False else f'{nm}+{off:#06x} {m} C={C:#x} len={l}: {t}')

