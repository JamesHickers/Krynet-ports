package community.krynet.ports;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends Activity
{
    static
    {
        System.loadLibrary("krynet");
    }

    private native View createKrynetView();

    private native void destroyKrynet();

    @Override
    protected void onCreate(Bundle state)
    {
        super.onCreate(state);

        View view = createKrynetView();

        if (view == null)
        {
            finish();
            return;
        }

        setContentView(view);
    }

    @Override
    protected void onDestroy()
    {
        destroyKrynet();

        super.onDestroy();
    }
}
