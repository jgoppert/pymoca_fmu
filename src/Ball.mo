model Ball
	Real x, v;
	parameter Real g = 9.8;
	parameter Real c = 0.1;
equation
	der(x) = v;
	der(v) = -g;
	when(x < 0) then
		reinit(v, -c*v);
	end when;
end Ball;
