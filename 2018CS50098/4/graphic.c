#define PY_SSIZE_T_CLEAN
#include <Python.h>

int graphic(int argc, char *argv[]) {
    wchar_t *program = Py_DecodeLocale(argv[0], NULL);
    if (program == NULL) {
        fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
        exit(1);
    }
    Py_SetProgramName(program); /* optional but recommended */
    Py_Initialize();
    
    PyRun_SimpleString("import matplotlib.pyplot as plt\n"
                       "import numpy as np\n"
                       "from matplotlib.animation import FuncAnimation\n"
    
                       "n = 2\n"
                       "m = np.ones(n)\n"
                       "x = np.zeros((n,2))\n"
                       "v = np.zeros((n,2))\n"
                       "f = np.zeros((n,2))\n"
                       "dt = 0.001\n"
    
                       "g = np.array([0,-9.8])\n"
    
                       "m[0] = 0.1\n"
                       "m[1] = 0.1\n"
                       "x[0,:] = np.array([0,0])\n"
                       "x[1,:] = np.array([1,0])\n"
                       "v[0,:] = np.array([4,3])\n"
                       "v[1,:] = np.array([-4,4])\n"
    
                       "def step():\n"
                       "\tf.fill(0)\n"
                       "\tfor i in range(n):\n"
                       "\t\tf[i,:] += m[i]*g\n"
                       "\tfor i in range(n):\n"
                       "\t\tv[i,:] += f[i,:]/m[i] * dt\n"
                       "\tfor i in range(n):\n"
                       "\t\tx[i,:] += v[i,:] * dt\n"
                       "\t\tif x[i,1] <= 0:\n"
                       "\t\t\tv[i,1] = -v[i,1]\n"
                       "\t\tif x[i,0] >= 1:\n"
                       "\t\t\tv[i,0] = -v[i,0]\n"
                       "\t\tif x[i,0] <= 0:\n"
                       "\t\t\tv[i,0] = -v[i,0]\n"
                       "\t\tif x[0,0] == x[1,0]:\n"
                       "\t\t\tv[0,0] = -v[0,0]\n"
                       "\t\t\tv[1,0] = -v[1,0]\n"
    
                       "fig, ax = plt.subplots()\n"
                       "points, = ax.plot(x[:,0], x[:,1], 'o')\n"
    
                       "def init():\n"
                       "\tax.set_xlim(0,1)\n"
                       "\tax.set_ylim(0,1)\n"
                       "\tax.set_aspect('equal')\n"
                       "\treturn points,\n"
    
                       "def animate(frame):\n"
                       "\tstep()\n"
                       "\tpoints.set_data(x[:,0], x[:,1])\n"
                       "\tif frame is frames-1:\n"
                       "\t\tplt.close()\n"
                       "\treturn points,\n"
    
                       "totalTime = 5\n"
                       "frames = int(totalTime/dt)\n"
                       "anim = FuncAnimation(fig, animate, frames=range(frames), init_func=init, interval=dt*1000)\n"
                       "plt.show()\n");
    
    if (Py_FinalizeEx() < 0) {
        exit(120);
    }
    PyMem_RawFree(program);
    return 0;
}
