type ErrorProps = {
  error: string;
  onExit: () => void;
};

const Error = ({ error, onExit }: ErrorProps) => (
  <div className="flex flex-col items-center">
    <div className="alert alert-error mb-2">{error}</div>
    <button className="btn btn-link" onClick={onExit}>
      Back to setup
    </button>
  </div>
);

export default Error;
